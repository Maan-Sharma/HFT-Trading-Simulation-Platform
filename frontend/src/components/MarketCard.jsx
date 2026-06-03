function MarketCard({ symbol, price, change }) {
  return (
    <div className="flex items-center gap-3 rounded-lg border border-slate-700 bg-slate-900 px-4 py-2">
      <span className="text-xs text-slate-400">
        {symbol}
      </span>

      <span className="font-medium text-white">
        {price}
      </span>

      <span className="text-sm text-green-400">
        {change}
      </span>
    </div>
  );
}

export default MarketCard;