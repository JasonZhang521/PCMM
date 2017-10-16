#!/bin/sh
message="\n
==============NVSMI LOG==============\n
\n
Timestamp                           : Thu Oct 12 15:50:39 2017\n
Driver Version                      : 384.69\n
\n
Attached GPUs                       : 2\n
GPU 00000000:02:00.0\n
    Product Name                    : Quadro GP100\n
    Product Brand                   : Quadro\n
    Display Mode                    : Disabled\n
    Display Active                  : Disabled\n
    Persistence Mode                : Disabled\n
    Accounting Mode                 : Disabled\n
    Accounting Mode Buffer Size     : 1920\n
    Driver Model\n
        Current                     : N/A\n
        Pending                     : N/A\n
    Serial Number                   : 0321617046343\n
    GPU UUID                        : GPU-62ff2127-2722-8b57-53a7-ace036fd672e\n
    Minor Number                    : 0\n
    VBIOS Version                   : 86.00.3A.00.0A\n
    MultiGPU Board                  : No\n
    Board ID                        : 0x200\n
    GPU Part Number                 : 900-5H400-2200-000\n
    Inforom Version\n
        Image Version               : H400.0500.01.04\n
        OEM Object                  : 1.1\n
        ECC Object                  : 4.1\n
        Power Management Object     : N/A\n
    GPU Operation Mode\n
        Current                     : N/A\n
        Pending                     : N/A\n
    GPU Virtualization Mode\n
        Virtualization mode         : None\n
    PCI\n
        Bus                         : 0x02\n
        Device                      : 0x00\n
        Domain                      : 0x0000\n
        Device Id                   : 0x15F010DE\n
        Bus Id                      : 00000000:02:00.0\n
        Sub System Id               : 0x11C310DE\n
        GPU Link Info\n
            PCIe Generation\n
                Max                 : 3\n
                Current             : 3\n
            Link Width\n
                Max                 : 16x\n
                Current             : 16x\n
        Bridge Chip\n
            Type                    : N/A\n
            Firmware                : N/A\n
        Replays since reset         : 0\n
        Tx Throughput               : 1000 KB/s\n
        Rx Throughput               : 1000 KB/s\n
    Fan Speed                       : 35 %\n
    Performance State               : P0\n
    Clocks Throttle Reasons\n
        Idle                        : Not Active\n
        Applications Clocks Setting : Not Active\n
        SW Power Cap                : Not Active\n
        HW Slowdown                 : Not Active\n
        Sync Boost                  : Not Active\n
        SW Thermal Slowdown         : Not Active\n
    FB Memory Usage\n
        Total                       : 16273 MiB\n
        Used                        : 0 MiB\n
        Free                        : 16273 MiB\n
    BAR1 Memory Usage\n
        Total                       : 256 MiB\n
        Used                        : 2 MiB\n
        Free                        : 254 MiB\n
    Compute Mode                    : Default\n
    Utilization\n
        Gpu                         : 0 %\n
        Memory                      : 0 %\n
        Encoder                     : 0 %\n
        Decoder                     : 0 %\n
    Encoder Stats\n
        Active Sessions             : 0\n
        Average FPS                 : 0\n
        Average Latency             : 0\n
    Ecc Mode\n
        Current                     : Disabled\n
        Pending                     : Disabled\n
    ECC Errors\n
        Volatile\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
        Aggregate\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
    Retired Pages\n
        Single Bit ECC              : N/A\n
        Double Bit ECC              : N/A\n
        Pending                     : N/A\n
    Temperature\n
        GPU Current Temp            : 51 C\n
        GPU Shutdown Temp           : 93 C\n
        GPU Slowdown Temp           : 90 C\n
        Memory Current Temp         : N/A\n
        Memory Max Operating Temp   : N/A\n
    Power Readings\n
        Power Management            : Supported\n
        Power Draw                  : 40.42 W\n
        Power Limit                 : 235.00 W\n
        Default Power Limit         : 235.00 W\n
        Enforced Power Limit        : 235.00 W\n
        Min Power Limit             : 117.50 W\n
        Max Power Limit             : 235.00 W\n
    Clocks\n
        Graphics                    : 1303 MHz\n
        SM                          : 1303 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1164 MHz\n
    Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Default Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Max Clocks\n
        Graphics                    : 1556 MHz\n
        SM                          : 1556 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1404 MHz\n
    Max Customer Boost Clocks\n
        Graphics                    : 1556 MHz\n
    Clock Policy\n
        Auto Boost                  : N/A\n
        Auto Boost Default          : N/A\n
    Processes                       : None\n
\n
GPU 00000000:03:00.0\n
    Product Name                    : Quadro GP100\n
    Product Brand                   : Quadro\n
    Display Mode                    : Disabled\n
    Display Active                  : Disabled\n
    Persistence Mode                : Disabled\n
    Accounting Mode                 : Disabled\n
    Accounting Mode Buffer Size     : 1920\n
    Driver Model\n
        Current                     : N/A\n
        Pending                     : N/A\n
    Serial Number                   : 0321617046633\n
    GPU UUID                        : GPU-fa958a68-62a9-34b2-ab58-4b89c9c34073\n
    Minor Number                    : 1\n
    VBIOS Version                   : 86.00.3A.00.0A\n
    MultiGPU Board                  : No\n
    Board ID                        : 0x300\n
    GPU Part Number                 : 900-5H400-2200-000\n
    Inforom Version\n
        Image Version               : H400.0500.01.04\n
        OEM Object                  : 1.1\n
        ECC Object                  : 4.1\n
        Power Management Object     : N/A\n
    GPU Operation Mode\n
        Current                     : N/A\n
        Pending                     : N/A\n
    GPU Virtualization Mode\n
        Virtualization mode         : None\n
    PCI\n
        Bus                         : 0x03\n
        Device                      : 0x00\n
        Domain                      : 0x0000\n
        Device Id                   : 0x15F010DE\n
        Bus Id                      : 00000000:03:00.0\n
        Sub System Id               : 0x11C310DE\n
        GPU Link Info\n
            PCIe Generation\n
                Max                 : 3\n
                Current             : 3\n
            Link Width\n
                Max                 : 16x\n
                Current             : 16x\n
        Bridge Chip\n
            Type                    : N/A\n
            Firmware                : N/A\n
        Replays since reset         : 0\n
        Tx Throughput               : 1000 KB/s\n
        Rx Throughput               : 0 KB/s\n
    Fan Speed                       : 32 %\n
    Performance State               : P0\n
    Clocks Throttle Reasons\n
        Idle                        : Not Active\n
        Applications Clocks Setting : Not Active\n
        SW Power Cap                : Active\n
        HW Slowdown                 : Not Active\n
        Sync Boost                  : Not Active\n
        SW Thermal Slowdown         : Not Active\n
    FB Memory Usage\n
        Total                       : 16273 MiB\n
        Used                        : 0 MiB\n
        Free                        : 16273 MiB\n
    BAR1 Memory Usage\n
        Total                       : 256 MiB\n
        Used                        : 2 MiB\n
        Free                        : 254 MiB\n
    Compute Mode                    : Default\n
    Utilization\n
        Gpu                         : 3 %\n
        Memory                      : 0 %\n
        Encoder                     : 0 %\n
        Decoder                     : 0 %\n
    Encoder Stats\n
        Active Sessions             : 0\n
        Average FPS                 : 0\n
        Average Latency             : 0\n
    Ecc Mode\n
        Current                     : Disabled\n
        Pending                     : Disabled\n
    ECC Errors\n
        Volatile\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
        Aggregate\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
    Retired Pages\n
        Single Bit ECC              : N/A\n
        Double Bit ECC              : N/A\n
        Pending                     : N/A\n
    Temperature\n
        GPU Current Temp            : 48 C\n
        GPU Shutdown Temp           : 93 C\n
        GPU Slowdown Temp           : 90 C\n
        Memory Current Temp         : N/A\n
        Memory Max Operating Temp   : N/A\n
    Power Readings\n
        Power Management            : Supported\n
        Power Draw                  : 28.00 W\n
        Power Limit                 : 235.00 W\n
        Default Power Limit         : 235.00 W\n
        Enforced Power Limit        : 235.00 W\n
        Min Power Limit             : 117.50 W\n
        Max Power Limit             : 235.00 W\n
    Clocks\n
        Graphics                    : 759 MHz\n
        SM                          : 759 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 835 MHz\n
    Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Default Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Max Clocks\n
        Graphics                    : 1556 MHz\n
        SM                          : 1556 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1404 MHz\n
    Max Customer Boost Clocks\n
        Graphics                    : 1556 MHz\n
    Clock Policy\n
        Auto Boost                  : N/A\n
        Auto Boost Default          : N/A\n
    Processes                       : None\n
\n
\n
==============NVSMI LOG==============\n
\n
Timestamp                           : Mon Oct 16 10:35:50 2017\n
Driver Version                      : 384.69\n
\n
Attached GPUs                       : 2\n
GPU 00000000:02:00.0\n
    Product Name                    : Quadro GP100\n
    Product Brand                   : Quadro\n
    Display Mode                    : Disabled\n
    Display Active                  : Disabled\n
    Persistence Mode                : Disabled\n
    Accounting Mode                 : Disabled\n
    Accounting Mode Buffer Size     : 1920\n
    Driver Model\n
        Current                     : N/A\n
        Pending                     : N/A\n
    Serial Number                   : 0321617046343\n
    GPU UUID                        : GPU-62ff2127-2722-8b57-53a7-ace036fd672e\n
    Minor Number                    : 0\n
    VBIOS Version                   : 86.00.3A.00.0A\n
    MultiGPU Board                  : No\n
    Board ID                        : 0x200\n
    GPU Part Number                 : 900-5H400-2200-000\n
    Inforom Version\n
        Image Version               : H400.0500.01.04\n
        OEM Object                  : 1.1\n
        ECC Object                  : 4.1\n
        Power Management Object     : N/A\n
    GPU Operation Mode\n
        Current                     : N/A\n
        Pending                     : N/A\n
    GPU Virtualization Mode\n
        Virtualization mode         : None\n
    PCI\n
        Bus                         : 0x02\n
        Device                      : 0x00\n
        Domain                      : 0x0000\n
        Device Id                   : 0x15F010DE\n
        Bus Id                      : 00000000:02:00.0\n
        Sub System Id               : 0x11C310DE\n
        GPU Link Info\n
            PCIe Generation\n
                Max                 : 3\n
                Current             : 3\n
            Link Width\n
                Max                 : 16x\n
                Current             : 16x\n
        Bridge Chip\n
            Type                    : N/A\n
            Firmware                : N/A\n
        Replays since reset         : 0\n
        Tx Throughput               : 1000 KB/s\n
        Rx Throughput               : 1000 KB/s\n
    Fan Speed                       : 36 %\n
    Performance State               : P0\n
    Clocks Throttle Reasons\n
        Idle                        : Not Active\n
        Applications Clocks Setting : Not Active\n
        SW Power Cap                : Not Active\n
        HW Slowdown                 : Not Active\n
        Sync Boost                  : Not Active\n
        SW Thermal Slowdown         : Not Active\n
    FB Memory Usage\n
        Total                       : 16273 MiB\n
        Used                        : 0 MiB\n
        Free                        : 16273 MiB\n
    BAR1 Memory Usage\n
        Total                       : 256 MiB\n
        Used                        : 2 MiB\n
        Free                        : 254 MiB\n
    Compute Mode                    : Default\n
    Utilization\n
        Gpu                         : 0 %\n
        Memory                      : 0 %\n
        Encoder                     : 0 %\n
        Decoder                     : 0 %\n
    Encoder Stats\n
        Active Sessions             : 0\n
        Average FPS                 : 0\n
        Average Latency             : 0\n
    Ecc Mode\n
        Current                     : Disabled\n
        Pending                     : Disabled\n
    ECC Errors\n
        Volatile\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
        Aggregate\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
    Retired Pages\n
        Single Bit ECC              : N/A\n
        Double Bit ECC              : N/A\n
        Pending                     : N/A\n
    Temperature\n
        GPU Current Temp            : 52 C\n
        GPU Shutdown Temp           : 93 C\n
        GPU Slowdown Temp           : 90 C\n
        Memory Current Temp         : N/A\n
        Memory Max Operating Temp   : N/A\n
    Power Readings\n
        Power Management            : Supported\n
        Power Draw                  : 40.42 W\n
        Power Limit                 : 235.00 W\n
        Default Power Limit         : 235.00 W\n
        Enforced Power Limit        : 235.00 W\n
        Min Power Limit             : 117.50 W\n
        Max Power Limit             : 235.00 W\n
    Clocks\n
        Graphics                    : 1303 MHz\n
        SM                          : 1303 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1164 MHz\n
    Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Default Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Max Clocks\n
        Graphics                    : 1556 MHz\n
        SM                          : 1556 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1404 MHz\n
    Max Customer Boost Clocks\n
        Graphics                    : 1556 MHz\n
    Clock Policy\n
        Auto Boost                  : N/A\n
        Auto Boost Default          : N/A\n
    Processes                       : None\n
\n
GPU 00000000:03:00.0\n
    Product Name                    : Quadro GP100\n
    Product Brand                   : Quadro\n
    Display Mode                    : Disabled\n
    Display Active                  : Disabled\n
    Persistence Mode                : Disabled\n
    Accounting Mode                 : Disabled\n
    Accounting Mode Buffer Size     : 1920\n
    Driver Model\n
        Current                     : N/A\n
        Pending                     : N/A\n
    Serial Number                   : 0321617046633\n
    GPU UUID                        : GPU-fa958a68-62a9-34b2-ab58-4b89c9c34073\n
    Minor Number                    : 1\n
    VBIOS Version                   : 86.00.3A.00.0A\n
    MultiGPU Board                  : No\n
    Board ID                        : 0x300\n
    GPU Part Number                 : 900-5H400-2200-000\n
    Inforom Version\n
        Image Version               : H400.0500.01.04\n
        OEM Object                  : 1.1\n
        ECC Object                  : 4.1\n
        Power Management Object     : N/A\n
    GPU Operation Mode\n
        Current                     : N/A\n
        Pending                     : N/A\n
    GPU Virtualization Mode\n
        Virtualization mode         : None\n
    PCI\n
        Bus                         : 0x03\n
        Device                      : 0x00\n
        Domain                      : 0x0000\n
        Device Id                   : 0x15F010DE\n
        Bus Id                      : 00000000:03:00.0\n
        Sub System Id               : 0x11C310DE\n
        GPU Link Info\n
            PCIe Generation\n
                Max                 : 3\n
                Current             : 3\n
            Link Width\n
                Max                 : 16x\n
                Current             : 16x\n
        Bridge Chip\n
            Type                    : N/A\n
            Firmware                : N/A\n
        Replays since reset         : 0\n
        Tx Throughput               : 1000 KB/s\n
        Rx Throughput               : 1000 KB/s\n
    Fan Speed                       : 33 %\n
    Performance State               : P0\n
    Clocks Throttle Reasons\n
        Idle                        : Not Active\n
        Applications Clocks Setting : Not Active\n
        SW Power Cap                : Not Active\n
        HW Slowdown                 : Not Active\n
        Sync Boost                  : Not Active\n
        SW Thermal Slowdown         : Not Active\n
    FB Memory Usage\n
        Total                       : 16273 MiB\n
        Used                        : 0 MiB\n
        Free                        : 16273 MiB\n
    BAR1 Memory Usage\n
        Total                       : 256 MiB\n
        Used                        : 2 MiB\n
        Free                        : 254 MiB\n
    Compute Mode                    : Default\n
    Utilization\n
        Gpu                         : 2 %\n
        Memory                      : 0 %\n
        Encoder                     : 0 %\n
        Decoder                     : 0 %\n
    Encoder Stats\n
        Active Sessions             : 0\n
        Average FPS                 : 0\n
        Average Latency             : 0\n
    Ecc Mode\n
        Current                     : Disabled\n
        Pending                     : Disabled\n
    ECC Errors\n
        Volatile\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
        Aggregate\n
            Single Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
            Double Bit            \n
                Device Memory       : N/A\n
                Register File       : N/A\n
                L1 Cache            : N/A\n
                L2 Cache            : N/A\n
                Texture Memory      : N/A\n
                Texture Shared      : N/A\n
                CBU                 : N/A\n
                Total               : N/A\n
    Retired Pages\n
        Single Bit ECC              : N/A\n
        Double Bit ECC              : N/A\n
        Pending                     : N/A\n
    Temperature\n
        GPU Current Temp            : 49 C\n
        GPU Shutdown Temp           : 93 C\n
        GPU Slowdown Temp           : 90 C\n
        Memory Current Temp         : N/A\n
        Memory Max Operating Temp   : N/A\n
    Power Readings\n
        Power Management            : Supported\n
        Power Draw                  : 29.20 W\n
        Power Limit                 : 235.00 W\n
        Default Power Limit         : 235.00 W\n
        Enforced Power Limit        : 235.00 W\n
        Min Power Limit             : 117.50 W\n
        Max Power Limit             : 235.00 W\n
    Clocks\n
        Graphics                    : 1088 MHz\n
        SM                          : 1088 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 987 MHz\n
    Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Default Applications Clocks\n
        Graphics                    : 1303 MHz\n
        Memory                      : 715 MHz\n
    Max Clocks\n
        Graphics                    : 1556 MHz\n
        SM                          : 1556 MHz\n
        Memory                      : 715 MHz\n
        Video                       : 1404 MHz\n
    Max Customer Boost Clocks\n
        Graphics                    : 1556 MHz\n
    Clock Policy\n
        Auto Boost                  : N/A\n
        Auto Boost Default          : N/A\n
    Processes                       : None\n
\n
"

if [ "$1" == "-q" ]; then
echo -e $message
fi
