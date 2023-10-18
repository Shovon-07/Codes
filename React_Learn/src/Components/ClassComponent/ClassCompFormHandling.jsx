import React from "react";

class ClassCompFormHandling extends React.Component {
  state = {
    name: "Shovon",
    email: "shovon@gmail.com",
    comment: "I love React",
    selectValue: "Subscriber",
    checked: "checked",
  };

  handleValue = (e) => {
    if (e.target.type === "text") {
      this.setState({
        name: e.target.value,
      });
    } else if (e.target.type === "email") {
      this.setState({
        email: e.target.value,
      });
    } else if (e.target.type === "textarea") {
      this.setState({
        comment: e.target.value,
      });
    } else if (e.target.type === "select-one") {
      this.setState({
        selectValue: e.target.value,
      });
    } else if (e.target.type === "checkbox") {
      this.setState({
        checked: e.target.checked,
      });
    }

    /*
    this.setState({
      name: e.target.value,
      email: e.target.value,
      comment: e.target.value,
    });
    */
  };

  submit = (e) => {
    e.preventDefault();
    const { name, email, comment, selectValue, checked } = this.state;
    console.log(name, email, comment, selectValue, checked);
  };

  render() {
    return (
      <>
        <h3 className="text-danger">Class Component Form Handling start</h3>
        <br />

        <form action="" onSubmit={this.submit}>
          <div>
            <input
              type="text"
              placeholder="Enter Name"
              value={this.state.name}
              onChange={this.handleValue}
            />
          </div>
          <div>
            <input
              type="email"
              placeholder="Enter Email"
              value={this.state.email}
              onChange={this.handleValue}
            />
          </div>
          <div>
            <textArea placeholder="Comment" onChange={this.handleValue}>
              {this.state.comment}
            </textArea>
          </div>
          <div>
            <select
              name=""
              id=""
              value={this.state.selectValue}
              onChange={this.handleValue}
            >
              <option value="Admin">Admin</option>
              <option value="Editor">Editor</option>
              <option value="Modarator">Modarator</option>
              <option value="Subscriber">Subscriber</option>
            </select>
          </div>
          <div>
            <input
              type="checkbox"
              id="checkBox"
              checked={this.state.checked}
              onChange={this.handleValue}
            />
            <span id="checkBox" style={{ cursor: "pointer" }}>
              Do you want to allow
            </span>
          </div>
          <div>
            <input type="submit" value="submit" />
          </div>
        </form>

        <br />
        <br />
        <h3 className="text-danger">Class Component Form Handling end</h3>
      </>
    );
  }
}

export default ClassCompFormHandling;
