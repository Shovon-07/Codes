import React from "react";

class ClassState extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      name: "____",
      count: 0,
      autocount: 0,
    };
  }

  // Change value
  ChangeName = (e) => {
    if (e.target.value === "") {
      this.setState({
        name: "____",
      });
    } else {
      this.setState({
        name: e.target.value,
      });
    }
  };

  // Counter
  Counter = () => {
    this.setState({
      count: this.state.count + 1,
    });
  };

  // Autometic Counter
  StartCount = () => {
    this.startCount = setInterval(() => {
      this.setState({
        autocount: this.state.autocount + 1,
      });
    }, 100);
  };
  PauseCount = () => {
    clearInterval(this.startCount);
  };
  ResetCount = () => {
    clearInterval(this.startCount);
    this.setState({
      autocount: 0,
    });
  };

  render() {
    return (
      <>
        <h3>State in Class component</h3>
        {/* Change value */}
        <input
          type="text"
          placeholder="Enter your name"
          onChange={this.ChangeName}
        />
        <h3>My Name is {this.state.name}</h3>
        <br />

        {/* Counter */}
        <h3>Count : {this.state.count}</h3>
        <button onClick={this.Counter}>Counter</button>
        <br />
        <br />

        {/* Autometic Counter */}
        <h3>Auto count : {this.state.autocount}</h3>
        <button onClick={this.StartCount}>Start</button>
        <span className="mx-4"></span>
        <button onClick={this.PauseCount}>Pause</button>
        <span className="mx-4"></span>
        <button onClick={this.ResetCount}>Reset</button>
        <br />
      </>
    );
  }
}
export default ClassState;
