import React from "react";
import withCounter_HOC from "./withCounter_HOC";

const HoverCounter_HOC = (props) => {
  const { ClickCount, ClickCounter } = props;
  return (
    <>
      <br />
      <button onMouseOver={ClickCounter}>Hovered {ClickCount} times</button>

      <br />
      <h1 className="text-danger">Higher oreder Component End</h1>
    </>
  );
};

export default withCounter_HOC(HoverCounter_HOC);
