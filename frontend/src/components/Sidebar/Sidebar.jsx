import { NavLink } from "react-router-dom";

const Sidebar = () => {
  return (
    <aside className="w-64 border-r border-gray-700 p-4">
      <nav className="flex flex-col gap-2">
        <NavLink to="/">
          Dashboard
        </NavLink>

        <NavLink to="/trading">
          Trading
        </NavLink>

        <NavLink to="/analytics">
          Analytics
        </NavLink>
      </nav>
    </aside>
  );
};

export default Sidebar;