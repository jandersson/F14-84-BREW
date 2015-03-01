import QtQuick 2.0
import Material.ListItems 0.1 as ListItem
import Material 0.1
import Material.Extras 0.1

Item{
    anchors.fill: parent
    anchors.margins: 20
    View {
        width: parent.width
        height: col_timers.implicitHeight
        elevation: 1
        Column{
            id: col_timers
            anchors.fill: parent
            ListItem.Header{
                text: "Timers"
            }
            ListItem.Standard{
                id: timer_session
                text: "Session Timer  00:00:00"
                secondaryItem: Row{

                    Button{
                    text: "Start"
                    anchors.verticalCenter: parent.verticalCenter
                    }
                    Button{
                    text: "Destroy"
                    anchors.verticalCenter: parent.verticalCenter
                    }

                }
            }
            ListItem.Standard{
                id: timer_create
                secondaryItem: Button{
                    text: "New Timer"
                }
            }
        }
    }
}

