import React from 'react';
import './Calendar.css';
import FullCalendar from '@fullcalendar/react';
import dayGridPlugin from '@fullcalendar/daygrid';
import interactionPlugin, {DateClickArg} from "@fullcalendar/interaction";
import {DayCellMountArg, DidMountHandler, EventClickArg} from "@fullcalendar/core";

type Props = {
  events: { title: string; date: string; }[];
  clickOnEmptyTile: (arg: DateClickArg) => void;
  clickOnEvent: (arg: EventClickArg) => void;
  dayCellDidMount?: DidMountHandler<DayCellMountArg>;
};

class CalendarComponent extends React.Component<Props> {
  render() {
    const {
      events,
      clickOnEmptyTile,
      clickOnEvent,
      dayCellDidMount
    } = this.props;

    return (
      <div className={"calendar"}>
        <FullCalendar
          plugins={[ dayGridPlugin, interactionPlugin ]}
          initialView="dayGridMonth"
          events={events}
          dateClick={clickOnEmptyTile}
          eventClick={clickOnEvent}
          dayCellDidMount={dayCellDidMount}
        />
      </div>
    )
  }
}

export default CalendarComponent;
