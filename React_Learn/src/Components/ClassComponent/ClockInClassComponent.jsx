import React, { useRef, useState } from "react";

class ClockInClassComponent extends React.Component {
  constructor(props) {
    super(props);

    // state = {...}-> It set a state value
    this.state = { date: new Date().toLocaleTimeString() };
  }

  componentDidMount() {
    this.runClock = setInterval(() => {
      // setState()-> It update states value
      this.setState({ date: new Date().toLocaleTimeString(this.props.lang) });
    }, 1000);
  }

  // componentWillUnmount() {
  //   clearInterval(this.runClock);
  // }

  render() {
    return (
      <>
        <h2 className="text-light">{this.state.date}</h2>
      </>
    );
  }
}

export default ClockInClassComponent;
