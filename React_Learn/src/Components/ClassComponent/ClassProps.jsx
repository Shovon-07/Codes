import React from "react";

class ClassProps extends React.Component {
  render() {
    const { style, msg } = this.props;
    return (
      <>
        <br />
        <h3>Props in Class component</h3>

        <p style={style}>{msg}</p>

        <br />
      </>
    );
  }
}
export default ClassProps;
