import QtQuick 2.3

Row {
    id: rowStages
    x: 0
    y: 0
    width: 800
    height: 71
    transformOrigin: Item.Center
    layoutDirection: Qt.RightToLeft
    spacing: 121
    z: 0

    Text {
        id: text6
        text: qsTr("Chill")
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignLeft
        z: 2
        font.pixelSize: 12
    }

    Text {
        id: txtBoil
        text: qsTr("Boil")
        z: 2
        font.pixelSize: 12
    }

    Text {
        id: txtSparge
        text: qsTr("Sparge")
        z: 2
        font.pixelSize: 12
    }

    Text {
        id: txtMash
        text: qsTr("Mash")
        z: 2
        font.pixelSize: 12
    }

    Text {
        id: txtPrep
        text: qsTr("Prep")
        z: 2
        font.pixelSize: 12
    }

    Text {
        id: txtRecipe
        text: qsTr("Recipe")
        z: 2
        font.pixelSize: 12
    }

}
