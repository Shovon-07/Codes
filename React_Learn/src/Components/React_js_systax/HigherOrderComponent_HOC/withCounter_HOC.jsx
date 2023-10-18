import React from "react";

const withCounter_HOC = (OriginalComponent) => {
  class NewComponent extends React.Component {
    state = {
      ClickCount: 0,
      HoverCount: 0,
    };

    ClickCounter = () => {
      this.setState({
        ClickCount: (this.state.ClickCount += 1),
      });
    };

    render() {
      const { ClickCount } = this.state;
      return (
        <>
          <OriginalComponent
            ClickCount={ClickCount}
            ClickCounter={this.ClickCounter}
          />
        </>
      );
    }
  }
  return NewComponent;
};
export default withCounter_HOC;
