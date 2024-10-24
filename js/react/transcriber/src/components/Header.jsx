export default function Header() {
  return (
    <header className="flex items-center justify-between gap-4 p-4">
      <h1 className="font-medium">
        swift<span className="text-indigo-500">scribe</span>
      </h1>
      <button className="flex items-center gap-2 recordButton px-4 py-2 rounded-lg text-indigo-500">
        <p>New</p>
        <i className="fa-solid fa-plus"></i>
      </button>
    </header>
  );
}
