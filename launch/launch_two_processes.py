import signal

import launch
import launch_ros.actions


def generate_launch_description():
    generate_node = launch_ros.actions.Node(package='ros2_signal_handling',
                                            node_executable='ros2_generate_data',
                                            output='both')

    process_node = launch_ros.actions.Node(package='ros2_signal_handling',
                                           node_executable='ros2_process_data',
                                           output='both')

    return launch.LaunchDescription([generate_node,
                                     process_node,

                                     launch.actions.RegisterEventHandler(
                                         event_handler=launch.event_handlers.OnProcessExit(
                                             target_action=generate_node,
                                             on_exit=[launch.actions.EmitEvent(
                                                 event=launch.events.process.SignalProcess(
                                                     signal_number=signal.SIGINT,
                                                     process_matcher=launch.events.matches_action(process_node)))],
                                         )),
                                     ])
