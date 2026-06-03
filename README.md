# HFT Trading Simulation Platform

A high-performance trading system simulator built in modern C++20.

This project is designed to replicate the core components used inside electronic exchanges, quantitative trading firms, and high-frequency trading (HFT) environments.

The goal is to progressively build a low-latency trading stack from scratch while following industry-level architecture and engineering practices.

---

## Current Features

### Order Management

* Limit Order support
* Buy and Sell side orders
* Timestamped orders
* FIFO order priority within price levels

### Order Book

* Separate Bid and Ask books
* Price Level management
* Best Bid calculation
* Best Ask calculation

### Matching Engine

* Incoming orders processed against resting liquidity
* Trade generation
* Partial fills
* Remaining quantity added back to the order book

### Market Data Feed

* Continuous random order generation
* Simulated market activity
* Configurable order rates

### WebSocket Infrastructure

* Boost.Beast based WebSocket server
* Real-time market data streaming foundation
* Ready for frontend integration

---

## Current Project Structure

```text
backend
│
├── apps
│   └── exchange
│       └── main.cpp
│
├── include
│   ├── book
│   ├── common
│   ├── feed
│   ├── matching
│   ├── network
│   ├── order
│   └── trade
│
├── src
│   ├── book
│   ├── feed
│   ├── matching
│   └── network
│
└── CMakeLists.txt
```

---

## Technology Stack

### Backend

* C++20
* STL
* Boost.Asio
* Boost.Beast
* CMake

### Frontend (Planned)

* React
* TypeScript
* WebSocket API
* Trading Dashboard

---

## How To Build

### Requirements

Install:

* MSYS2 UCRT64
* GCC 15+
* CMake 4+
* Boost 1.90+

Verify installation:

```bash
g++ --version
cmake --version
```

---

### Build

```bash
cd backend

mkdir build
cd build

cmake .. -G "MinGW Makefiles"

cmake --build .
```

---

### Run

```bash
./exchange.exe
```

Example output:

```text
BUY 45 @ 252
BEST BID: 252
BEST ASK: 253

TRADE 20 @ 252

BUY 30 @ 253
BEST BID: 253
BEST ASK: 253
```

---

## Current Architecture

```text
MarketDataFeed
        ↓
MatchingEngine
        ↓
OrderBook
        ↓
Trade Generation
        ↓
Console Output
```

---

## Future Roadmap

### Phase 1 — Exchange Core

* [x] Order structures
* [x] Price levels
* [x] Order book
* [x] Matching engine
* [x] Trade generation
* [x] Market data simulation

### Phase 2 — Real-Time Streaming

* [x] WebSocket server foundation
* [ ] JSON market messages
* [ ] Trade broadcasting
* [ ] Order book broadcasting

Architecture:

```text
Matching Engine
        ↓
Market Publisher
        ↓
WebSocket Server
        ↓
Frontend
```

---

### Phase 3 — Trading Dashboard

* [ ] React frontend
* [ ] Live order book
* [ ] Trade tape
* [ ] Market statistics
* [ ] Orders per second
* [ ] Trades per second
* [ ] Latency monitoring

---

### Phase 4 — Advanced Exchange Features

* [ ] Market orders
* [ ] Order cancellation
* [ ] Order modification
* [ ] Iceberg orders
* [ ] Stop orders
* [ ] Order persistence

---

### Phase 5 — Quant Infrastructure

* [ ] Strategy engine
* [ ] Backtesting engine
* [ ] Risk engine
* [ ] Position tracking
* [ ] PnL calculations
* [ ] Performance analytics

---

### Phase 6 — HFT Features

* [ ] Lock-free queues
* [ ] Memory pools
* [ ] Custom allocator
* [ ] Multi-threaded matching
* [ ] CPU affinity
* [ ] Latency benchmarking
* [ ] Nanosecond timestamps
* [ ] Market replay engine

---

## Project Vision

The long-term objective is to build a realistic simulation of an electronic exchange and quantitative trading platform.

The completed system will include:

* Exchange Matching Engine
* Market Data Feed Handler
* Strategy Engine
* Risk Management System
* Backtesting Framework
* Real-Time Dashboard
* Latency Monitoring Tools

This project serves as a learning platform for:

* High-Frequency Trading (HFT)
* Quantitative Development
* Exchange Design
* Low-Latency Systems
* Modern C++ Engineering
* Distributed Market Infrastructure

---

## Disclaimer

This project is intended for educational and research purposes. It is not designed for production trading or financial advice.
