import React from "react";

const FunctionalProps = (props) => {
  return (
    <>
      <br />
      <h3>Props</h3>
      <p style={props.style}>{props.msg}</p>

      <br />
    </>
  );
};

export default FunctionalProps;
