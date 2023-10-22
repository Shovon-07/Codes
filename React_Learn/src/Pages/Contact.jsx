import React from "react";

/* Routing */
import { useNavigate } from "react-router-dom";

const Contact = () => {
  /* Routing */
  const navigation = useNavigate();
  const goBack = () => {
    navigation(-1);
  };

  return (
    <>
      <h2>Contact Me</h2>
      <div>
        <input type="text" name="" placeholder="Name" />
      </div>
      <div>
        <input type="email" name="" placeholder="Email" />
      </div>
      <div>
        <textarea name="" cols="30" rows="10" placeholder="Comments"></textarea>
      </div>

      {/* Routing */}
      <button onClick={goBack}>Go Back</button>
    </>
  );
};

export default Contact;
