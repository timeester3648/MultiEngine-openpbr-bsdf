#pragma once

#include <MultiEngine/math/geometry/Vectors.h>

#define OPENPBR_USE_CUSTOM_INTEROP 1

using vec2 = MultiEngine::Vector<float32, 2>;
using vec3 = MultiEngine::Vector<float32, 3>;
using vec4 = MultiEngine::Vector<float32, 4>;
using uint = uint32;

// Boolean vector types (returned by component-wise comparison helpers below).
using bvec2 = MultiEngine::Vector<bool, 2>;
using bvec3 = MultiEngine::Vector<bool, 3>;
using bvec4 = MultiEngine::Vector<bool, 4>;

// ---------------------------------------------------------------------------
// Memory qualifiers / address space specifiers.
// C++ does not use function-parameter address space qualifiers.
// ---------------------------------------------------------------------------

#define ADDRESS_SPACE_THREAD

// ---------------------------------------------------------------------------
// Parameter passing macros.
// C++ uses references for output and input/output parameters.
// ---------------------------------------------------------------------------

#define OUT(type)       type&
#define INOUT(type)     type&
#define CONST_REF(type) const type&

// ---------------------------------------------------------------------------
// Constant declaration macros.
// C++ uses constexpr for compile-time constants.
// Global constants use static inline constexpr for ODR safety.
// ---------------------------------------------------------------------------

#define CONSTEXPR_LOCAL  constexpr
#define CONSTEXPR_GLOBAL static inline constexpr

// ---------------------------------------------------------------------------
// Constexpr function qualifiers.
// C++ supports constexpr functions directly.
// ---------------------------------------------------------------------------

#define GENERAL_CONSTEXPR_FUNCTION  static constexpr
#define LIMITED_CONSTEXPR_FUNCTION  static constexpr

// ---------------------------------------------------------------------------
// Function inline specifier.
// ---------------------------------------------------------------------------

#define INLINE_FUNCTION inline

// ---------------------------------------------------------------------------
// Swizzle helpers.
// Self-contained implementations — no external extension required.
// ---------------------------------------------------------------------------

INLINE_FUNCTION vec2 openpbr_swizzle_xy(const vec3 v)
{
    return vec2(v.x, v.y);
}
INLINE_FUNCTION vec2 openpbr_swizzle_xy(const vec4 v)
{
    return vec2(v.x, v.y);
}
INLINE_FUNCTION vec3 openpbr_swizzle_xyz(const vec4 v)
{
    return vec3(v.x, v.y, v.z);
}

#define SWIZZLE(v, suffix) openpbr_swizzle_##suffix(v)

// ---------------------------------------------------------------------------
// Struct-construction helpers for aggregate types.
// clang-format off
// ---------------------------------------------------------------------------

#define MAKE_STRUCT_1(type, a1) type{a1}
#define MAKE_STRUCT_2(type, a1, a2) type{a1, a2}
#define MAKE_STRUCT_3(type, a1, a2, a3) type{a1, a2, a3}
#define MAKE_STRUCT_4(type, a1, a2, a3, a4) type{a1, a2, a3, a4}
#define MAKE_STRUCT_5(type, a1, a2, a3, a4, a5) type{a1, a2, a3, a4, a5}
#define MAKE_STRUCT_6(type, a1, a2, a3, a4, a5, a6) type{a1, a2, a3, a4, a5, a6}
#define MAKE_STRUCT_7(type, a1, a2, a3, a4, a5, a6, a7) type{a1, a2, a3, a4, a5, a6, a7}
#define MAKE_STRUCT_8(type, a1, a2, a3, a4, a5, a6, a7, a8) type{a1, a2, a3, a4, a5, a6, a7, a8}
#define MAKE_STRUCT_9(type, a1, a2, a3, a4, a5, a6, a7, a8, a9) type{a1, a2, a3, a4, a5, a6, a7, a8, a9}
#define MAKE_STRUCT_10(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10}
#define MAKE_STRUCT_11(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11}
#define MAKE_STRUCT_12(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12}
#define MAKE_STRUCT_13(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13}
#define MAKE_STRUCT_14(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14}
#define MAKE_STRUCT_15(type, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) type{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15}
// clang-format on

// ---------------------------------------------------------------------------
// Specialization constants default to compile-time constants in C++ mode.
// ---------------------------------------------------------------------------

#define DECLARE_SPECIALIZATION_CONSTANT(constant_id_number, name, default_value) \
    CONSTEXPR_GLOBAL bool name = default_value
#define GET_SPECIALIZATION_CONSTANT(name) name

// ---------------------------------------------------------------------------
// Assert macros.
// ---------------------------------------------------------------------------

#define ASSERT(expr, message)      MLE_CORE_ASSERT((expr), (message))
#define ASSERT_UNREACHABLE(message) MLE_CORE_ASSERT(false, (message)); MLE_UNREACHABLE()
#define STATIC_ASSERT(expr, message) static_assert(expr, message)

// ---------------------------------------------------------------------------
// Scalar math functions
//
// For float32 scalars we delegate to <cmath>.  The vector overloads apply the
// operation component-wise through MultiEngine's mutating member functions,
// working on a local copy so the originals are not modified.
// ---------------------------------------------------------------------------

// abs
INLINE_FUNCTION float32 abs(const float32 x) { return MultiEngine::abs(x); }
INLINE_FUNCTION vec2  abs(vec2 v) { v.abs(); return v; }
INLINE_FUNCTION vec3  abs(vec3 v) { v.abs(); return v; }
INLINE_FUNCTION vec4  abs(vec4 v) { v.abs(); return v; }

// acos
INLINE_FUNCTION float32 acos(const float32 x) { return MultiEngine::acos(x); }
INLINE_FUNCTION vec2  acos(vec2 v) { v.acos(); return v; }
INLINE_FUNCTION vec3  acos(vec3 v) { v.acos(); return v; }
INLINE_FUNCTION vec4  acos(vec4 v) { v.acos(); return v; }

// asin
INLINE_FUNCTION float32 asin(const float32 x) { return MultiEngine::asin(x); }
INLINE_FUNCTION vec2  asin(vec2 v) { v.asin(); return v; }
INLINE_FUNCTION vec3  asin(vec3 v) { v.asin(); return v; }
INLINE_FUNCTION vec4  asin(vec4 v) { v.asin(); return v; }

// atan  (one-argument form; two-argument atan2 form not needed by OpenPBR)
INLINE_FUNCTION float32 atan(const float32 x) { return MultiEngine::atan(x); }
INLINE_FUNCTION vec2  atan(vec2 v) { v.atan(); return v; }
INLINE_FUNCTION vec3  atan(vec3 v) { v.atan(); return v; }
INLINE_FUNCTION vec4  atan(vec4 v) { v.atan(); return v; }

// atan (two-argument atan2 form used in some OpenPBR expressions)
INLINE_FUNCTION float32 atan(const float32 y, const float32 x) { return MultiEngine::atan2(y, x); }

// cos
INLINE_FUNCTION float32 cos(const float32 x) { return MultiEngine::cos(x); }
INLINE_FUNCTION vec2  cos(vec2 v) { v.cos(); return v; }
INLINE_FUNCTION vec3  cos(vec3 v) { v.cos(); return v; }
INLINE_FUNCTION vec4  cos(vec4 v) { v.cos(); return v; }

// sin
INLINE_FUNCTION float32 sin(const float32 x) { return MultiEngine::sin(x); }
INLINE_FUNCTION vec2  sin(vec2 v) { v.sin(); return v; }
INLINE_FUNCTION vec3  sin(vec3 v) { v.sin(); return v; }
INLINE_FUNCTION vec4  sin(vec4 v) { v.sin(); return v; }

// exp
INLINE_FUNCTION float32 exp(const float32 x) { return MultiEngine::exp(x); }
INLINE_FUNCTION vec2  exp(vec2 v) { v.exp(); return v; }
INLINE_FUNCTION vec3  exp(vec3 v) { v.exp(); return v; }
INLINE_FUNCTION vec4  exp(vec4 v) { v.exp(); return v; }

// log
INLINE_FUNCTION float32 log(const float32 x) { return MultiEngine::log(x); }
INLINE_FUNCTION vec2  log(vec2 v) { v.log(); return v; }
INLINE_FUNCTION vec3  log(vec3 v) { v.log(); return v; }
INLINE_FUNCTION vec4  log(vec4 v) { v.log(); return v; }

// sqrt
INLINE_FUNCTION float32 sqrt(const float32 x) { return MultiEngine::sqrt(x); }
INLINE_FUNCTION vec2  sqrt(vec2 v) { v.sqrt(); return v; }
INLINE_FUNCTION vec3  sqrt(vec3 v) { v.sqrt(); return v; }
INLINE_FUNCTION vec4  sqrt(vec4 v) { v.sqrt(); return v; }

// pow
INLINE_FUNCTION float32 pow(const float32 x, const float32 e) { return MultiEngine::pow(x, e); }
INLINE_FUNCTION vec2  pow(vec2 v, const float32 e) { v.pow(e); return v; }
INLINE_FUNCTION vec3  pow(vec3 v, const float32 e) { v.pow(e); return v; }
INLINE_FUNCTION vec4  pow(vec4 v, const float32 e) { v.pow(e); return v; }
INLINE_FUNCTION vec2  pow(vec2 v, const vec2 e) { v.pow(e); return v; }
INLINE_FUNCTION vec3  pow(vec3 v, const vec3 e) { v.pow(e); return v; }
INLINE_FUNCTION vec4  pow(vec4 v, const vec4 e) { v.pow(e); return v; }

// floor
INLINE_FUNCTION float32 floor(const float32 x) { return MultiEngine::floor(x); }
INLINE_FUNCTION vec2  floor(vec2 v) { v.floor(); return v; }
INLINE_FUNCTION vec3  floor(vec3 v) { v.floor(); return v; }
INLINE_FUNCTION vec4  floor(vec4 v) { v.floor(); return v; }

// ceil
INLINE_FUNCTION float32 ceil(const float32 x) { return MultiEngine::ceil(x); }
INLINE_FUNCTION vec2  ceil(vec2 v) { v.ceil(); return v; }
INLINE_FUNCTION vec3  ceil(vec3 v) { v.ceil(); return v; }
INLINE_FUNCTION vec4  ceil(vec4 v) { v.ceil(); return v; }

// min / max — scalar delegates to MultiEngine::; vector delegates to MultiEngine clamp
INLINE_FUNCTION float32 min(const float32 a, const float32 b) { return MultiEngine::min(a, b); }
INLINE_FUNCTION float32 max(const float32 a, const float32 b) { return MultiEngine::max(a, b); }
INLINE_FUNCTION vec2  min(vec2 v, const vec2  hi) { v.clamp(MultiEngine::Vector<float32,2>(std::numeric_limits<float32>::lowest()), hi); return v; }
INLINE_FUNCTION vec3  min(vec3 v, const vec3  hi) { v.clamp(MultiEngine::Vector<float32,3>(std::numeric_limits<float32>::lowest()), hi); return v; }
INLINE_FUNCTION vec4  min(vec4 v, const vec4  hi) { v.clamp(MultiEngine::Vector<float32,4>(std::numeric_limits<float32>::lowest()), hi); return v; }
INLINE_FUNCTION vec2  min(vec2 v, const float32 hi) { v.clamp(std::numeric_limits<float32>::lowest(), hi); return v; }
INLINE_FUNCTION vec3  min(vec3 v, const float32 hi) { v.clamp(std::numeric_limits<float32>::lowest(), hi); return v; }
INLINE_FUNCTION vec4  min(vec4 v, const float32 hi) { v.clamp(std::numeric_limits<float32>::lowest(), hi); return v; }
INLINE_FUNCTION vec2  max(vec2 v, const vec2  lo) { v.clamp(lo, MultiEngine::Vector<float32,2>(std::numeric_limits<float32>::max())); return v; }
INLINE_FUNCTION vec3  max(vec3 v, const vec3  lo) { v.clamp(lo, MultiEngine::Vector<float32,3>(std::numeric_limits<float32>::max())); return v; }
INLINE_FUNCTION vec4  max(vec4 v, const vec4  lo) { v.clamp(lo, MultiEngine::Vector<float32,4>(std::numeric_limits<float32>::max())); return v; }
INLINE_FUNCTION vec2  max(vec2 v, const float32 lo) { v.clamp(lo, std::numeric_limits<float32>::max()); return v; }
INLINE_FUNCTION vec3  max(vec3 v, const float32 lo) { v.clamp(lo, std::numeric_limits<float32>::max()); return v; }
INLINE_FUNCTION vec4  max(vec4 v, const float32 lo) { v.clamp(lo, std::numeric_limits<float32>::max()); return v; }

// clamp
INLINE_FUNCTION float32 clamp(const float32 x, const float32 lo, const float32 hi) { return MultiEngine::clamp(x, lo, hi); }
INLINE_FUNCTION vec2  clamp(vec2 v, const vec2  lo, const vec2  hi) { v.clamp(lo, hi); return v; }
INLINE_FUNCTION vec3  clamp(vec3 v, const vec3  lo, const vec3  hi) { v.clamp(lo, hi); return v; }
INLINE_FUNCTION vec4  clamp(vec4 v, const vec4  lo, const vec4  hi) { v.clamp(lo, hi); return v; }
INLINE_FUNCTION vec2  clamp(vec2 v, const float32 lo, const float32 hi) { v.clamp(lo, hi); return v; }
INLINE_FUNCTION vec3  clamp(vec3 v, const float32 lo, const float32 hi) { v.clamp(lo, hi); return v; }
INLINE_FUNCTION vec4  clamp(vec4 v, const float32 lo, const float32 hi) { v.clamp(lo, hi); return v; }

// mix  (GLSL linear interpolation — delegates to MultiEngine lerp)
INLINE_FUNCTION float32 mix(const float32 a, const float32 b, const float32 t) { return a + t * (b - a); }
INLINE_FUNCTION vec2  mix(vec2 a, const vec2  b, const float32 t) { a.lerp(b, t); return a; }
INLINE_FUNCTION vec3  mix(vec3 a, const vec3  b, const float32 t) { a.lerp(b, t); return a; }
INLINE_FUNCTION vec4  mix(vec4 a, const vec4  b, const float32 t) { a.lerp(b, t); return a; }
INLINE_FUNCTION vec2  mix(vec2 a, const vec2  b, const vec2  t) { a.lerp(b, t); return a; }
INLINE_FUNCTION vec3  mix(vec3 a, const vec3  b, const vec3  t) { a.lerp(b, t); return a; }
INLINE_FUNCTION vec4  mix(vec4 a, const vec4  b, const vec4  t) { a.lerp(b, t); return a; }

// smoothstep
INLINE_FUNCTION float32 smoothstep(const float32 edge0, const float32 edge1, const float32 x)
{
    const float32 t = MultiEngine::clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}
INLINE_FUNCTION vec3 smoothstep(const float32 edge0, const float32 edge1, const vec3& x)
{
    return vec3(
        smoothstep(edge0, edge1, x.x),
        smoothstep(edge0, edge1, x.y),
        smoothstep(edge0, edge1, x.z));
}
INLINE_FUNCTION vec3 smoothstep(const vec3& edge0, const vec3& edge1, const vec3& x)
{
    return vec3(
        smoothstep(edge0.x, edge1.x, x.x),
        smoothstep(edge0.y, edge1.y, x.y),
        smoothstep(edge0.z, edge1.z, x.z));
}

// ---------------------------------------------------------------------------
// Geometric functions
// ---------------------------------------------------------------------------

// dot
INLINE_FUNCTION float32 dot(const vec2& a, const vec2& b) { return a.dot(b); }
INLINE_FUNCTION float32 dot(const vec3& a, const vec3& b) { return a.dot(b); }
INLINE_FUNCTION float32 dot(const vec4& a, const vec4& b) { return a.dot(b); }

// length
INLINE_FUNCTION float32 length(const vec2& v) { return v.length(); }
INLINE_FUNCTION float32 length(const vec3& v) { return v.length(); }
INLINE_FUNCTION float32 length(const vec4& v) { return v.length(); }

// normalize
INLINE_FUNCTION vec2 normalize(vec2 v) { v.normalize(); return v; }
INLINE_FUNCTION vec3 normalize(vec3 v) { v.normalize(); return v; }
INLINE_FUNCTION vec4 normalize(vec4 v) { v.normalize(); return v; }

// cross (vec3 only)
INLINE_FUNCTION vec3 cross(const vec3& a, const vec3& b) { return a.cross(b); }

// reflect
INLINE_FUNCTION vec3 reflect(const vec3& v, const vec3& n) { return v.reflect(n); }

// ---------------------------------------------------------------------------
// Vector comparison functions — return bvecN (component-wise bool vectors).
// OpenPBR uses these in boolean expressions; bvec is never named explicitly.
// ---------------------------------------------------------------------------

// equal
INLINE_FUNCTION bvec2 equal(const vec2& a, const vec2& b) { return a.equals_component_wise(b); }
INLINE_FUNCTION bvec3 equal(const vec3& a, const vec3& b) { return a.equals_component_wise(b); }
INLINE_FUNCTION bvec4 equal(const vec4& a, const vec4& b) { return a.equals_component_wise(b); }

// notEqual
INLINE_FUNCTION bvec2 notEqual(const vec2& a, const vec2& b) { return a.not_equals_component_wise(b); }
INLINE_FUNCTION bvec3 notEqual(const vec3& a, const vec3& b) { return a.not_equals_component_wise(b); }
INLINE_FUNCTION bvec4 notEqual(const vec4& a, const vec4& b) { return a.not_equals_component_wise(b); }

// greaterThan
INLINE_FUNCTION bvec2 greaterThan(const vec2& a, const vec2& b) { return a.greater_component_wise(b); }
INLINE_FUNCTION bvec3 greaterThan(const vec3& a, const vec3& b) { return a.greater_component_wise(b); }
INLINE_FUNCTION bvec4 greaterThan(const vec4& a, const vec4& b) { return a.greater_component_wise(b); }

// greaterThanEqual
INLINE_FUNCTION bvec2 greaterThanEqual(const vec2& a, const vec2& b) { return a.greater_or_equal_component_wise(b); }
INLINE_FUNCTION bvec3 greaterThanEqual(const vec3& a, const vec3& b) { return a.greater_or_equal_component_wise(b); }
INLINE_FUNCTION bvec4 greaterThanEqual(const vec4& a, const vec4& b) { return a.greater_or_equal_component_wise(b); }

// lessThan
INLINE_FUNCTION bvec2 lessThan(const vec2& a, const vec2& b) { return a.less_component_wise(b); }
INLINE_FUNCTION bvec3 lessThan(const vec3& a, const vec3& b) { return a.less_component_wise(b); }
INLINE_FUNCTION bvec4 lessThan(const vec4& a, const vec4& b) { return a.less_component_wise(b); }

// lessThanEqual
INLINE_FUNCTION bvec2 lessThanEqual(const vec2& a, const vec2& b) { return a.less_or_equal_component_wise(b); }
INLINE_FUNCTION bvec3 lessThanEqual(const vec3& a, const vec3& b) { return a.less_or_equal_component_wise(b); }
INLINE_FUNCTION bvec4 lessThanEqual(const vec4& a, const vec4& b) { return a.less_or_equal_component_wise(b); }

// ---------------------------------------------------------------------------
// Boolean reduction functions
// ---------------------------------------------------------------------------

INLINE_FUNCTION bool all(const bvec2& v) { return v.all(); }
INLINE_FUNCTION bool all(const bvec3& v) { return v.all(); }
INLINE_FUNCTION bool all(const bvec4& v) { return v.all(); }

INLINE_FUNCTION bool any(const bvec2& v) { return v.any(); }
INLINE_FUNCTION bool any(const bvec3& v) { return v.any(); }
INLINE_FUNCTION bool any(const bvec4& v) { return v.any(); }

INLINE_FUNCTION float32 saturate(const float32 x)
{
    return MultiEngine::saturate(x);
}

INLINE_FUNCTION vec2 saturate(vec2 v) { v.saturate(); return v; }
INLINE_FUNCTION vec3 saturate(vec3 v) { v.saturate(); return v; }
INLINE_FUNCTION vec4 saturate(vec4 v) { v.saturate(); return v; }

#include "../openpbr.h"