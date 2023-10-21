import React, { useState } from "react";
import UseState from "./UseState";
import Props from "./Props";
import UseEffect from "./UseEffect";
import UseRef from "./UseRef";
import UseReducer from "./UseReducer";

const FunctionalComponent = () => {
  const [show, setShow] = useState(true);

  const toggleComponent = () => {
    setShow(!show);
  };

  return (
    <>
      <h1 className="text-danger">Functional Component Start</h1>
      <br />

      <UseState />
      <Props style={{ color: "green" }} msg={"Functional Props"} />
      {/* {show && <FunctionalUseEffect />} */}

      {show == true ? <UseEffect /> : null}
      <br />
      <br />
      <button onClick={toggleComponent}>
        {show ? "Hide use effect" : "Show use effect"}
      </button>

      <br />
      <br />
      <UseRef />

      <br />
      <br />
      <UseReducer />

      <h1 className="text-danger">Functional Component End</h1>
    </>
  );
};
export default FunctionalComponent;
