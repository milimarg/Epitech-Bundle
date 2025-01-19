import React from 'react';
import { TextField, IconButton, InputAdornment, List, ListItem, ListItemText } from '@mui/material';
import SearchIcon from '@mui/icons-material/Search';
import ClearIcon from '@mui/icons-material/Clear';
import './SearchBar.css';

type SuggestionProps = {
  list: string[];
  validate?: (query: string, suggestion: string) => boolean;
  alwaysVisible?: boolean;
};

type Props = {
  onSearch: (query: string) => void;
  onChange: (query: string, filteredSuggestions: string[]) => void;
  placeholder?: string;
  debounceTime?: number;
  showSearchButton?: boolean;
  validateInput?: (query: string) => boolean;
  suggestionProps?: SuggestionProps;
};

type State = {
  query: string;
  isSuggestionsVisible: boolean;
  debouncedQuery: string;
  isValid: boolean;
  isFocused: boolean;
};

class SearchBar extends React.Component<Props, State> {
  private debounceTimeout: NodeJS.Timeout | null = null;

  static readonly defaultValidateSuggestion = (query: string, suggestion: string) => {
    return suggestion.toLowerCase().includes(query.toLowerCase());
  }

  static readonly defaultProps = {
    placeholder: 'Search...',
    debounceTime: 300,
    showSearchButton: true,
  };

  state: State = {
    query: '',
    isSuggestionsVisible: false,
    debouncedQuery: '',
    isValid: true,
    isFocused: false,
  };

  handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const query = e.target.value;
    const { debounceTime, onChange, validateInput, suggestionProps } = this.props;
    const { list, validate } = suggestionProps || { list: [] };
    const validateSuggestion = validate ?? SearchBar.defaultValidateSuggestion;

    const isValid = validateInput ? validateInput(query) : true;
    const filteredSuggestions = list
      ? list.filter((s) => validateSuggestion(query, s))
      : [];

    this.setState({ query, isSuggestionsVisible: true, isValid });

    if (this.debounceTimeout)
      clearTimeout(this.debounceTimeout);
    this.debounceTimeout = setTimeout(() => {
      onChange(query, filteredSuggestions);
      this.setState({ debouncedQuery: query });
    }, debounceTime);
  };

  handleClear = () => {
    const { onSearch } = this.props;

    this.setState({ query: '', isSuggestionsVisible: false });
    if (onSearch)
      onSearch('');
  };

  handleSearch = () => {
    const { query, isValid } = this.state;
    if (isValid) {
      this.setState({ isSuggestionsVisible: false });
      this.props.onSearch(query);
    }
  };

  handleSelectSuggestion = (suggestion: string) => {
    const { onChange, validateInput, suggestionProps } = this.props;
    const { list, validate } = suggestionProps ?? { list: [] };
    const validateSuggestion = validate ?? SearchBar.defaultValidateSuggestion;

    const isValid = validateInput ? validateInput(suggestion) : true;

    this.setState({ query: suggestion, isSuggestionsVisible: false, isValid });
    const filteredSuggestions = list.filter((s) => validateSuggestion(suggestion, s));

    if (onChange)
      onChange(suggestion, filteredSuggestions);
    if (this.props.onSearch)
      this.props.onSearch(suggestion);
  };

  handleKeyDown = (e: React.KeyboardEvent) => {
    if (e.key === 'Enter')
      this.handleSearch();
  };

  handleFocus = () => {
    const { query } = this.state;
    const { suggestionProps } = this.props;

    this.setState({
      isSuggestionsVisible: suggestionProps?.alwaysVisible || query.length > 0,
      isFocused: true,
    });
  };

  handleBlur = () => {
    this.setState({ isSuggestionsVisible: false, isFocused: false });
  };

  render() {
    const { query, isSuggestionsVisible, isValid, isFocused } = this.state;
    const { suggestionProps, placeholder, showSearchButton, onSearch } = this.props;
    const { list: suggestionList, validate } = suggestionProps ?? { list: [] };
    const validateSuggestion = validate ?? SearchBar.defaultValidateSuggestion;

    const filteredSuggestions = suggestionList.filter((s) => validateSuggestion(query, s));

    return (
      <div className="search-bar">
        <TextField
          fullWidth
          value={query}
          onChange={this.handleChange}
          onKeyDown={this.handleKeyDown}
          onFocus={this.handleFocus}
          onBlur={this.handleBlur}
          placeholder={placeholder}
          error={!isValid}
          helperText={!isValid ? 'Invalid input' : ''}
          slotProps={{
            input: {
              endAdornment: (
                <InputAdornment position="end">
                  {query && (
                    <IconButton onClick={this.handleClear}>
                      <ClearIcon />
                    </IconButton>
                  )}
                  {showSearchButton && (
                    <IconButton onClick={() => onSearch(query)}>
                      <SearchIcon />
                    </IconButton>
                  )}
                </InputAdornment>
              ),
            }
          }}
        />

        {(isFocused || query.length > 0) && isSuggestionsVisible && filteredSuggestions.length > 0 && (
          <List className="suggestions-list">
            {filteredSuggestions.map((suggestion) => (
              <ListItem
                component="li"
                key={suggestion}
                onMouseDown={() => this.handleSelectSuggestion(suggestion)}
              >
                <ListItemText primary={suggestion} />
              </ListItem>
            ))}
          </List>
        )}
      </div>
    );
  }
}

export default SearchBar;
