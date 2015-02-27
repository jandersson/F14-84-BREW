import QtQuick 2.0
import Material.ListItems 0.1 as ListItem
import Material 0.1
import Material.Extras 0.1
Item{
    anchors.fill: parent
    anchors.leftMargin: 20
    anchors.topMargin: 20
    View {
        width: units.dp(350)
        height: col_temperature.implicitHeight
        elevation: 1
            Column{
                id: col_temperature
                anchors.fill: parent
                ListItem.Header{
                    text: "Temperature"
                }
                ListItem.Standard{
                    text: "Hot Liqour Tank  72F"
                }
                ListItem.Standard{
                    text: "Mash Tun 72F"
                }
                ListItem.Standard{
                    text: "Boil Kettle  72F"
                }
            }
        }

}



