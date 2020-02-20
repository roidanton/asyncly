/*
 * Copyright 2019 LogMeIn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <algorithm>
#include <sstream>
#include <string>

#include "prometheus/client_metric.h"

namespace prometheus {
struct MetricFamily;
}

namespace asyncly {
namespace detail {

struct MetricSearchResult {
    bool success;
    prometheus::ClientMetric metric;
    std::string errorMessage;
};

MetricSearchResult grabMetric(
    const std::vector<prometheus::MetricFamily>& families,
    prometheus::MetricType type,
    const std::string& familyName,
    const std::string& labelValue);
}
}