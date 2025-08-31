#pragma once

namespace oss::safety {

// Link this object when OSS_FORBID_DYNAMIC_ALLOCATION=ON to forbid global new/delete.
struct no_global_new_delete_guard {
  no_global_new_delete_guard() = default;
};

}  // namespace oss::safety
