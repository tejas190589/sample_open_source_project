#include <new>
#include <cstdlib>

// When linked, delete global new/delete to prevent accidental dynamic allocation.
// This is a build-time policy; tests/examples may not link this TU.
void* operator new(std::size_t) = delete;
void* operator new[](std::size_t) = delete;
void operator delete(void*) noexcept = delete;
void operator delete[](void*) noexcept = delete;
