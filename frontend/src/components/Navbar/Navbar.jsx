import {
  Bell,
  Menu,
  Moon,
  Search,
} from "lucide-react";

import MarketCard from "../MarketCard";

const marketData = [
  {
    symbol: "NIFTY",
    price: "22534.25",
    change: "+0.89%",
  },
  {
    symbol: "BANKNIFTY",
    price: "48752.10",
    change: "+1.23%",
  },
];

function Navbar() {
  return (
    <header className="h-14 border-b border-slate-800 bg-[#08111f] px-4 flex items-center justify-between">

      {/* Left Section */}
      <div className="flex items-center gap-4">
        <div className="flex items-center gap-2">
          <span className="text-cyan-400 text-xl">
            📈
          </span>

          <h1 className="font-semibold text-white">
            Quant Terminal
          </h1>
        </div>

        <div className="h-6 w-px bg-slate-700" />

        <button>
          <Menu
            size={18}
            className="text-slate-400"
          />
        </button>
      </div>

      {/* Center Section */}
      <div className="flex items-center gap-3">
        {marketData.map((item) => (
          <MarketCard
            key={item.symbol}
            symbol={item.symbol}
            price={item.price}
            change={item.change}
          />
        ))}

        <div className="relative">
          <Search
            size={16}
            className="absolute left-3 top-1/2 -translate-y-1/2 text-slate-500"
          />

          <input
            type="text"
            placeholder="Search symbol..."
            className="w-72 rounded-lg border border-slate-700 bg-slate-900 py-2 pl-9 pr-4 text-sm outline-none"
          />
        </div>
      </div>

      {/* Right Section */}
      <div className="flex items-center gap-5">
        <div className="flex items-center gap-2 text-sm">
          <span className="h-2 w-2 rounded-full bg-green-500" />

          <span className="text-green-400">
            Market Open
          </span>

          <span className="text-slate-400">
            10:24:35
          </span>
        </div>

        <Bell
          size={18}
          className="cursor-pointer text-slate-300"
        />

        <Moon
          size={18}
          className="cursor-pointer text-slate-300"
        />

        <div className="flex h-8 w-8 items-center justify-center rounded-full bg-blue-600 text-sm font-semibold">
          AK
        </div>
      </div>
    </header>
  );
}

export default Navbar;