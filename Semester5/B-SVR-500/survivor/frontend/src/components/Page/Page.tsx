import React from "react";
import { Divider } from "@mui/material";
import "./Page.css"

type Props = {
  children: React.ReactNode;
  pageTitle?: string;
  pageSubtitle?: string;
};

class Page extends React.Component<Props> {

  render() {
    const { pageTitle, pageSubtitle, children } = this.props;

    return (
      <div className="page">
        <div className="page-wrapper">
          {pageTitle && (
            <div className="page-header">
              <h1>{pageTitle}</h1>
              <p>{pageSubtitle}</p>
            </div>
          )}
          {children}
        </div>
      </div>
    );
  }
}

export default Page;
