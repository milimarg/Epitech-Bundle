from copy import deepcopy
from country import Country


def fit2(countries: list[Country]):
    print("Fit2")
    year_acc = 0
    year_squared_acc = 0
    pop_acc = 0
    value_acc = 0
    first_country_pop = deepcopy(countries[0].population_by_year)
    list_years = list(first_country_pop)
    years_len = len(list_years)

    for i in range(1, len(countries)):
        temp: Country = countries[i]
        for year in list(temp.population_by_year):
            pop = temp.population_by_year[year]
            first_country_pop[year] += pop
    for year in list_years:
        current_pop = countries[0].population_by_year[year]
        year_acc += current_pop
        year_squared_acc += year
        pop_acc += pow(current_pop, 2)
        value_acc += year * current_pop
    result = years_len * pop_acc - pow(year_acc, 2)
    if result == 0:
        exit(84)
    a = (years_len * value_acc - year_acc * year_squared_acc) / result
    b = (year_squared_acc * pop_acc - year_acc * value_acc) / result
    return a, b
