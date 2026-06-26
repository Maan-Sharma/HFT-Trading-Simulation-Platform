import { Outlet } from "react-router-dom";
import Navbar from "../components/Navbar/Navbar";
import Sidebar from "../components/Sidebar/Sidebar";

const MainLayout = () => {
  return (
    <div className="h-screen bg-[#0f172a] text-white">
      <Navbar />

      <div className="flex h-[calc(100vh-64px)]">
        <Sidebar />

        <main className="flex-1 p-6 overflow-auto">
          <Outlet />
        </main>
      </div>
    </div>
  );
};

export default MainLayout;