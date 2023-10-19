import React from "react";
import FunctionalUseState from "./FunctionalUseState";
import FunctionalProps from "./FunctionalProps";

const FunctionalComponent = () => {
  return (
    <>
      <h1 className="text-danger">Functional Component Start</h1>
      <br />

      <FunctionalUseState />
      <FunctionalProps style={{ color: "green" }} msg={"Functional Props"} />

      <h1 className="text-danger">Functional Component End</h1>
    </>
  );
};
export default FunctionalComponent;
