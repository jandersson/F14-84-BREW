import QtQuick 2.0
import Material 0.1
import Material.ListItems 0.1 as ListItem

Item{
    anchors.fill: parent
    anchors.leftMargin: 20
    anchors.topMargin: 20
    anchors.rightMargin: 20
View{
        width: parent.width
        height: column.implicitHeight
        elevation: 1
        Column{
            id: column
            anchors.fill: parent
            ListItem.Header{
                text: "Mash Schedule"
            }
            Repeater{
                model: recipe.mashSteps
                delegate: ListItem.Subtitled{
                text: modelData.name
                subText: "Temp: " + modelData.temperature + " F"
                valueText: "Time: " + modelData.time + " min"
                }
            }
        }
    }
}
