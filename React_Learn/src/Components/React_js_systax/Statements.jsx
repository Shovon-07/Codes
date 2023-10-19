import React from "react";

const Statements = () => {
  let mark = 80;
  let cities = ["Rajshahi", "Dhaka", "Sylhet"];

  return (
    <>
      <h1 className="text-danger">Statemnts start</h1>
      {/* Short hand operator */}
      {mark >= 80 ? <p>Great result</p> : <p>Bad result</p>}

      {/* If else (immediately invoked function) */}
      {(() => {
        if (mark > 100 || mark < 0) {
          return <p>Please enter mark between 1-100</p>;
        } else if (mark >= 80) {
          return <p>You achive A+</p>;
        } else {
          return <p>You failed</p>;
        }
      })()}

      {/* Loop in array */}
      <ol>
        {cities.map((item, i) => {
          return <li>{item}</li>;
        })}
      </ol>

      <br />
      <h1 className="text-danger">Statemnts end</h1>
    </>
  );
};

export default Statements;
