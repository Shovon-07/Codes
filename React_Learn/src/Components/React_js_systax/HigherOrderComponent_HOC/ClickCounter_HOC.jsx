import React from "react";
import withCounter_HOC from "./withCounter_HOC";

const ClickCounter_HOC = (props) => {
  const { ClickCount, ClickCounter } = props;
  return (
    <>
      <h1 className="text-danger">Higher oreder Component Start</h1>
      <br />

      <button onClick={ClickCounter}>Clicked {ClickCount} times</button>
    </>
  );
};

export default withCounter_HOC(ClickCounter_HOC);
