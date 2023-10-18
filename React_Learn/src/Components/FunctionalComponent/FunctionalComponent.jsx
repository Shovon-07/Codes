import React from "react";
import FunctionalUseState from "./FunctionalUseState";

const FunctionalComponent = () => {
  return (
    <>
      <h1 className="text-danger">Functional Component Start</h1>
      <br />

      <FunctionalUseState />

      <h1 className="text-danger">Functional Component End</h1>
    </>
  );
};
export default FunctionalComponent;
