#include "uniforms_set.h"

namespace glm
{
    struct vec3 {};
    struct mat4 {};
}

EJK_DEFINE_UNIFORMS_SET(common_uniforms,
    EJK_UNIFORM(glm::mat4, mv       )
    EJK_UNIFORM(glm::mat4, proj     )
    EJK_UNIFORM(glm::vec3, light_dir)
);

void usage(common_uniforms & ufms)
{
    //ufms.mv->set({});
    //ufms.proj->set({});
}
