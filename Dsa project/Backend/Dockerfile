FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    g++ \
    libcpp-httplib-dev \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY main.cpp .

RUN g++ main.cpp -std=c++17 -O2 \
    -o server -lcpp-httplib -pthread

CMD ["./server"]