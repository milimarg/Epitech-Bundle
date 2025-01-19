import React from "react";
import Page from '../../components/Page/Page';
import BackendRequester from "../../utils/backendRequester";
import CircularProgress from '@mui/material/CircularProgress';
import { Tip } from "../../utils/types";
import "./Tips.css";
import {Accordion, AccordionDetails, AccordionSummary, Divider, styled} from "@mui/material";
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';

type Props = {
};

type State = {
  tips: Tip[],
  status: "loading" | "success" | "error",
  message?: string
};

const StyledAccordion = styled(Accordion)(({ theme }) => ({
  marginBottom: 0,
  '&.Mui-expanded': {
    margin: 0,
  },
}));

export default class Tips extends React.Component<Props, State> {
  state: State = {
    tips: [],
    status: "loading"
  };

  async componentDidMount() {
    try {
      const tipsData = await BackendRequester.fetchTips();
      if (BackendRequester.isFetchError(tipsData)) {
        this.setState({ status: "error",  message: tipsData.type + " " + tipsData.message });
        return;
      }
      if (Array.isArray(tipsData)) {
        const tips = tipsData.map((tip) => {
          return { ...tip };
        });
        this.setState({ tips, status: "success" });
      } else {
        this.setState({ status: "error", message: "Error fetching tips data: Invalid response"});
      }
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching tips data:" + error});
    }
  }


  render() {
    const { status, message } = this.state;
    let renderElement: React.ReactNode;

    switch (status) {
      case "loading":
        renderElement =
          <div className={"loading-screen"}>
            <CircularProgress color="inherit" />
          </div>;
        break;
      case "error":
        renderElement =
        <div className={"error-message"}>
            <p>{message}</p>
        </div>;
        break;
      case "success":
        renderElement =
        <div className={"tips-cards"}>
          {
            this.state.tips.map((tip, index) => {
              return (
                  <StyledAccordion key={index} sx={{ mb: 0 }}>
                    <AccordionSummary
                      expandIcon={<ExpandMoreIcon />}
                      className="accordion-summary"
                    >
                      {tip.title}
                    </AccordionSummary>
                    <Divider />
                    <AccordionDetails className="accordion-details" sx={{ p: 2.5 }}>
                      {tip.tip}
                    </AccordionDetails>
                  </StyledAccordion>
              );
            })
          }
        </div>
        break;
    }
    return (
      <Page pageTitle="Tips for Coaches">
        {renderElement}
      </Page>
    );
  };
}
