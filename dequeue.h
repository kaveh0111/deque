#include <utility>


constexpr std::size_t   NUM_BLOCKS = 2;
constexpr std::size_t   BLOCK_SIZE = 20;

template <typename T>
struct Controller{
    Controller() noexcept;
    ~Controller() noexcept;
    Controller(const Controller& other) = delete;
    Controller(Controller&& other) noexcept;
    Controller& operator=(const Controller& other) = delete;
    Controller& operator=(Controller&& other) noexcept;
    
    std::size_t m_block_size;
    std::size_t m_num_blocks;
    
};


template <typename T>
class dequeue{
    public:
    dequeue();
    ~dequeue();
    dequeue(const dequeue& other) = delete;
    dequeue(dequeue&& other) noexcept;
    dequeue& operator=(const dequeue& other) = delete;
    dequeue& operator=(dequeue&& other) noexcept;
    void push_back();
    void push_front();
    void emplace_back();
    void emplace_front();
    void pop_front();
    void pop_back();
    T& front();
    T& back();
    T* begin();
    T* end();
    T& operator*();
    T* operator->();
    T& operator[](std::size_t position);
    T& at(std::size_t position);
    
    const T& front() const;
    const T& back() const;
    const T* begin() const;
    const T* end() const;
    const T& operator*() const;
    const T* operator->() const;
    const T& operator[](std::size_t position) const;
    const T& at(std::size_t position) const;
    
    const T& cfront() const;
    const T& cback() const;
    const T* cbegin() const;
    const T* cend() const;
    T& cfront();
    T& cback();
    T* cbegin();
    T* cend();
    
    void clear() noexcept;
    bool empty() const noexcept;
    bool full() const noexcept;
    std::size_t size() const noexcept;
    
    const T* insert(std::size_t position);
    T* insert(const T* insert_position, const T* start, const T* end);
    void shrink_to_fit() noexcept;
    T* erase(T* position);
    T* erase(T* start_pos, T* end_pos);
    void resize(std::size_t new_size) noexcept;
    
    void swap(dequeue& other) noexcept;
    
    
    private:
    Controller<T> m_ctrl_block = nullptr;
    
    
};
