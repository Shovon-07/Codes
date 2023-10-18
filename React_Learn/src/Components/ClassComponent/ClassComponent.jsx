import React from "react";
import ClassState from "./ClassState";
import ClassProps from "./ClassProps";
import ClassCompFormHandling from "./ClassCompFormHandling";

class ClassComponent extends React.Component {
  render() {
    return (
      <>
        <h1 className="text-danger">Class Component Start</h1>
        <br />

        <ClassState />
        <ClassProps
          style={{
            color: "green",
            "font-weight": "bold",
          }}
          msg={"Class Props"}
        />
        <ClassCompFormHandling />

        <h1 className="text-danger">Class Component End</h1>
      </>
    );
  }
}
export default ClassComponent;
