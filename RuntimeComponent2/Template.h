#pragma once

#include "Template.g.h"

namespace winrt::RuntimeComponent2::implementation
{
    struct Template : TemplateT<Template>
    {
    };
}

namespace winrt::RuntimeComponent2::factory_implementation
{
    struct Template : TemplateT<Template, implementation::Template>
    {
    };
}
