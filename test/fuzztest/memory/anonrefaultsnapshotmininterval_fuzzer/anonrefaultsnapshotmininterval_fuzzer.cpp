/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * SPDX-License-Identifier: GPL-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstddef>
#include <cstdint>
#include "memorycommon.h"

namespace OHOS {
bool AnonRefaultSnapshotMinIntervalFuzzer(const uint8_t *data, size_t size)
{
    const char *anonRefaultSnapshotMinInterval = "/dev/memcg/memory.anon_refault_snapshot_min_interval";
    bool ret = MemoryFuzzTest(data, size, anonRefaultSnapshotMinInterval);
    return ret;
}
} // namespace OHOS

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    OHOS::AnonRefaultSnapshotMinIntervalFuzzer(data, size);
    return 0;
}
