import React from "react";

// Functional component
/*
const MyComponent = (props) => {
  function clickFunctionBtn() {
    alert("You clicked class component btn");
  }
  return (
    <>
    <h1 className="text-danger">My Componetn start</h1>

      <h1 className="text-danger">This is functional component</h1>
      
        <p className="text-danger">This is functional component</p>
        <br />
        <p className="text-danger">{this.props.msg} in functional component</p>

        <button onClick={clickFunctionBtn}>Click function button</button>

        <br />
        <br />
        <h1 className="text-danger">My Componetn end</h1>

        <br />
        <br />


      <br />
      <br />
    </>
  );
};
*/

// Class component
class MyComponent extends React.Component {
  state = { title: "My Component" };

  clickClassBtn = () => {
    this.setState({ title: "This is class component button's view" });
  };

  render() {
    return (
      <>
        <h1 className="text-danger">My Componetn start</h1>
        <p className="text-danger">This is class component</p>
        <br />
        <p className="text-danger">{this.props.msg} in class component</p>

        <br />
        <p>{this.state.title}</p>
        <button onClick={this.clickClassBtn}>Click class button</button>

        <br />
        <br />
        <h1 className="text-danger">My Componetn end</h1>

        <br />
        <br />
      </>
    );
  }
}

export default MyComponent;
