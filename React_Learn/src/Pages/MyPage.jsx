import React from "react";

// Pass parameter/id
import { useParams } from "react-router-dom";

const MyPage = () => {
  const { id } = useParams();
  return (
    <>
      <h1>This is MyPage</h1>
    </>
  );
};

export default MyPage;
