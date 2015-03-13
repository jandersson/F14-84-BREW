import QtQuick 2.2
import QtQuick.Dialogs 1.0

FileDialog{
    id: filedialog
    title: "Choose a recipe XML file"
    onAccepted: {
        console.log("File selected: " + filedialog.fileUrl)
        filedialog.close()
    }
    onRejected: {
        console.log("Operation canceled")
        filedialog.close()
    }

}
