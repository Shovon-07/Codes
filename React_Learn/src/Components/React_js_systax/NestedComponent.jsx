import React from "react";

class NestedComponent extends React.Component {
  render() {
    return (
      <>
        <br />
        <br />

        <h1 className="text-danger">This is Nested Component</h1>

        {/* For use header */}
        {this.props.children}

        <br />
        <br />
      </>
    );
  }
}

export default NestedComponent;
