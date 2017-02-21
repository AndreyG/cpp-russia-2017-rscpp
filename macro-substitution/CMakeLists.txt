add_library(macro-substitution-example
  usage.cpp
  uniform.h
  uniform_fwd.h
  shader_program.h
  uniforms_set.h
)

target_include_directories(macro-substitution-example PRIVATE ${Boost_INCLUDE_DIRS})