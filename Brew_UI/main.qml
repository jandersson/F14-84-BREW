import QtQuick 2.3
import QtQuick.Controls 1.1
import Material 0.1
import Material.ListItems 0.1 as ListItem
ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 480
    title: qsTr("Abbey Ridge Automated Brewery")
    initialPage: myPage
    theme {
        primaryColor: "#993333"
        accentColor: "#993333"
    }
    Page{
        id: myPage
        title: "Abbey Ridge Automated Brewery"
        anchors.fill: parent
        tabs: [
            {text: "Recipe"},
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
                id: recipePage
                width: tabView.width
                height: tabView.height
                color: "#999"
            }
            Rectangle{
                id: prepPage
                width: tabView.width
                height: tabView.height
                color: "#999"
                TemperatureCard{}
            }
            Rectangle{
                id: mashPage
                width: tabView.width
                height: tabView.height
                color: "#999"
                TemperatureCard{

                }
                Button{
                    id: btn_startSparge
                    anchors.right parent
                    text: "Begin Sparge"
                    elevation: 1
                    onClicked: myPage.selectedTab = 3
                }

            }
            Rectangle{
                id: spargePage
                width: tabView.width
                height: tabView.height
                color: "#999"
                TemperatureCard{id: spargeTempCard}
                PumpControls{}
            }
            Rectangle{
                id: chillPage
                width: tabView.width
                height: tabView.height
                color: "#999"
                TemperatureCard{}
                PumpControls{}
            }
        }
    }
    Snackbar{
        id: snackbar
    }
}
