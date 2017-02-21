#pragma once

#include "shader_program.h"

#include <boost/preprocessor/seq/for_each.hpp>

#define EJK_UNIFORM_TYPE(field)     BOOST_PP_TUPLE_ELEM(0, field)
#define EJK_UNIFORM_CT_NAME(field)  BOOST_PP_TUPLE_ELEM(1, field)
#define EJK_UNIFORM_RT_NAME(field)  BOOST_PP_TUPLE_ELEM(2, field)

#define EJK_DECLARE_UNIFORM(r, data, field) \
    ::ejk::UniformPtr<EJK_UNIFORM_TYPE(field)> EJK_UNIFORM_CT_NAME(field);

#define EJK_DECLARE_UNIFORMS_SET_FIELDS(fields)      \
    BOOST_PP_SEQ_FOR_EACH(EJK_DECLARE_UNIFORM, fake_data, fields)

#define EJK_DEFINE_UNIFORM_INITIALIZER(_, sp, field) \
    EJK_UNIFORM_CT_NAME(field)(::ejk::cast<EJK_UNIFORM_TYPE(field)>(sp.uniform(EJK_UNIFORM_RT_NAME(field))))

#define EJK_DEFINE_UNIFORM_INITIALIZER_AFTER_COMMA(_, sp, field) \
    , EJK_DEFINE_UNIFORM_INITIALIZER(_, sp, field)

#define EJK_DEFINE_UNIFORMS_SET_CONSTRUCTOR(class_name, fields)                                             \
    explicit class_name(::ejk::IShaderProgram & sp)                                                         \
        : EJK_DEFINE_UNIFORM_INITIALIZER(_, sp, BOOST_PP_SEQ_HEAD(fields))                                  \
          BOOST_PP_SEQ_FOR_EACH(EJK_DEFINE_UNIFORM_INITIALIZER_AFTER_COMMA, sp, BOOST_PP_SEQ_TAIL(fields))  \
    {}

#define EJK_DEFINE_UNIFORMS_SET(name, fields)               \
    struct name                                             \
    {                                                       \
        EJK_DECLARE_UNIFORMS_SET_FIELDS(fields)             \
        EJK_DEFINE_UNIFORMS_SET_CONSTRUCTOR(name, fields)   \
    }

#define EJK_UNIFORM(type, name) \
    ((type, name, #name))
