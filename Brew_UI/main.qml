import QtQuick 2.3
import QtQuick.Controls 1.1
import Material 0.1
import Material.ListItems 0.1 as ListItem
ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 480
    title: qsTr("F14-84-BREW Automated Brewery")
    initialPage: myPage
    theme {
        primaryColor: "#993333"
        accentColor: "#993333"
    }
    Page{
        id: myPage
        anchors.fill: parent
        tabs: [
            {text: "Recipe",
             width: 500},
            {text: "Prep"},
            {text: "Mash"},
            {text: "Sparge"},
            {text: "Chill"}
        ]

        TabView {
            id: tabView
            model: tabs
            anchors.fill: parent
            currentIndex: myPage.selectedTab
        }

        VisualItemModel{
            id: tabs
            Rectangle{
                width: tabView.width
                height: tabView.height
                color: "#999"
            }
            Rectangle{
                width: tabView.width
                height: tabView.height
                color: "#EEE"
            }
            Rectangle{
                width: tabView.width
                height: tabView.height
                color: "#999"
            }
            Rectangle{
                width: tabView.width
                height: tabView.height
            }
            Rectangle{
                width: tabView.width
                height: tabView.height
            }
        }
    }

}
