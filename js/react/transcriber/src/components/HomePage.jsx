export default function HomePage() {
  return (
    <main className="flex-1 p-4 flex flex-col gap-3 text-center sm:gap-4 md:gap-5 justify-center pb-20">
      <h1 className="font-semibold text-5xl sm:text-6xl md:text-7xl">
        swift<span className="text-indigo-500 bold">scribe</span>
      </h1>

      <h3 className="font-medium md:text-lg">
        {" "}
        Record
        <span className="text-indigo-600">&rarr;</span> Transcribe
        <span className="text-indigo-600">&rarr;</span> Translate
      </h3>

      <button className="flex recordButton px-4 py-2 rounded-xl items-center text-base justify-between gap-4 mx-auto w-72 max-w-full my-4">
        <p className="text-indigo-500">Record</p>
        <i className="fa-solid fa-microphone cursor-pointer hover:text-red-700 duration-200"></i>
      </button>
      <p className="text-base">
        or{" "}
        <label className="text-sky-700 cursor-pointer hover:text-blue-600 duration-200">
          upload <input className="hidden" type="file" accept=".mp3,.wave" />
        </label>{" "}
        a file <span className="text-red-800 text-sm">(*.mp3)</span>
      </p>
      <p className="italic text-slate-500">
        Turn minutes of speech into seconds of text
      </p>
    </main>
  );
}
