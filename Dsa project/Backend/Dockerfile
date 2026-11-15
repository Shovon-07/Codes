FROM debian:bookworm-slim

# প্রয়োজনীয় টুলস ইনস্টল করা
RUN apt-get update && apt-get install -y \
    g++ \
    curl \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# প্রথমে প্রজেক্টের ফাইলগুলো কপি করুন (main.cpp, Graph.h, Wishlist.h)
COPY . .

# এরপর সরাসরি কন্টেইনারের ভেতরে httplib.h ডাউনলোড করে নিন
RUN curl -sSL https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -o httplib.h

# সবশেষে সার্ভার কম্পাইল করুন
RUN g++ main.cpp -std=c++17 -O2 -o server -pthread

EXPOSE 8080

CMD ["./server"]

# FROM debian:bookworm-slim

# RUN apt-get update && apt-get install -y \
#     g++ \
#     libcpp-httplib-dev \
#     nlohmann-json3-dev \
#     && rm -rf /var/lib/apt/lists/*

# WORKDIR /app

# COPY main.cpp .

# RUN g++ main.cpp -std=c++17 -O2 \
#     -o server -lcpp-httplib -pthread

# CMD ["./server"]