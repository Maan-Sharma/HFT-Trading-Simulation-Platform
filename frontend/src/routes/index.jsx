import { createBrowserRouter } from "react-router-dom";

import MainLayout from "../layouts/MainLayout";

import Dashboard from "../pages/Dashboard";
import Trading from "../pages/Trading";
import Analytics from "../pages/Analytics";
import NotFound from "../pages/NotFound";

export const router = createBrowserRouter([
  {
    path: "/",
    element: <MainLayout />,
    errorElement: <NotFound />,
    children: [
      {
        index: true,
        element: <Dashboard />,
      },
      {
        path: "trading",
        element: <Trading />,
      },
      {
        path: "analytics",
        element: <Analytics />,
      },
    ],
  },
]);