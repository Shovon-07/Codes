import React from "react";

const Props = (props) => {
  return (
    <>
      <h1 className="text-danger">React Props start</h1>
      <p>
        {props.title} <br /> {props.description}
      </p>

      <br />

      <ul>
        <li>{props.Object["name"]}</li>
        <li>{props.Object["age"]}</li>
      </ul>

      <br />

      <button onClick={props.Function}>Props Function</button>

      <br />
      <h1 className="text-danger">React Props end</h1>

      <br />
      <br />
    </>
  );
};

export default Props;
