import Header from "./components/Header.jsx";
import HomePage from "./components/HomePage.jsx";

import FilePage from "./components/FilePage.jsx";

import { useState } from "react";
function App() {
  const [recording, setRecording] = useState(null);
  const [audioFile, setAudioFile] = useState(null);

  const hasRecording = recording || audioFile;

  return (
    <div className="flex flex-col max-w-[1000px] mx-auto w-full">
      <section className="min-h-screen flex flex-col">
        <Header />
        {hasRecording ? <FilePage /> : <HomePage />}
      </section>
      <h1 className="text-emerald-600">Welcome!</h1>
      <footer></footer>
    </div>
  );
}

export default App;
