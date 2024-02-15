import React, { useState } from "react";

export default function FormManage() {
  let [formObj, setFormObj] = useState({
    name: "Shovon",
    email: "aa",
    city: "Rajshahi",
    gender: "Female",
  });

  const inputOnChange = (property, value) => {
    setFormObj((preObj) => ({
      ...preObj,
      [property]: value,
    }));
  };

  const submitForm = (e) => {
    e.preventDefault();
    console.log(formObj);
  };

  return (
    <div className="demo">
      <h1>Form manage</h1>
      <form onSubmit={submitForm}>
        <div>
          <input
            type="text"
            placeholder="Enter your name"
            value={formObj.name}
            onChange={(e) => inputOnChange("name", e.target.value)}
          />
        </div>
        <div>
          <input
            type="text"
            placeholder="Enter your email"
            value={formObj.email}
            onChange={(e) => inputOnChange("email", e.target.value)}
          />
        </div>
        <div>
          <select
            value={formObj.city}
            onChange={(e) => inputOnChange("city", e.target.value)}
          >
            <option value="">Choose city</option>
            <option value="Rajshahi">Rajshahi</option>
            <option value="Dhaka">Dhaka</option>
            <option value="Bogura">Bogura</option>
          </select>
        </div>
        <div>
          <input
            type="radio"
            id="male"
            name="gender"
            checked={formObj.gender == "Male"}
            onChange={() => inputOnChange("gender", "Male")}
          />
          <label for="male">Male</label>
          <input
            type="radio"
            id="female"
            name="gender"
            checked={formObj.gender == "Female"}
            onChange={() => inputOnChange("gender", "Female")}
          />
          <label for="female">Female</label>
        </div>
        <div>
          <input type="submit" value={"Submit"} />
        </div>
      </form>
    </div>
  );
}
