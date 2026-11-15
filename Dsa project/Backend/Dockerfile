FROM debian:bookworm-slim

# প্রয়োজনীয় বিল্ড টুলস ও কার্ল (curl) ইনস্টল করা
RUN apt-get update && apt-get install -y \
    g++ \
    curl \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# সরাসরি গিটহাব থেকে লেটেস্ট httplib.h হেডার ফাইলটি ডাউনলোড করে নেওয়া
RUN curl -sSL https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -o httplib.h

# প্রজেক্টের বাকি ফাইলগুলো কপি করা (main.cpp, Graph.h, Wishlist.h)
COPY . .

# সার্ভার কম্পাইল করা
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