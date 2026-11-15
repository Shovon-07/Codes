FROM debian:bookworm-slim

# প্রয়োজনীয় বিল্ড টুলস ও লাইব্রেরি ইনস্টল করা
RUN apt-get update && apt-get install -y \
    g++ \
    libcpp-httplib-dev \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# প্রজেক্টের সব ফাইল (main.cpp, Graph.h, Wishlist.h) কপি করা
COPY . .

# কোড কম্পাইল করা 
# (নোট: cpp-httplib হেডার-অনলি হওয়ায় -lcpp-httplib বাদ দেওয়া হয়েছে)
RUN g++ main.cpp -std=c++17 -O2 \
    -o server -pthread

# সার্ভার পোর্ট এক্সপোজ করা
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