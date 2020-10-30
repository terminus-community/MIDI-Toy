;; MIDI-Toy demo for HTTP protocol control.
;; Uses Drakma library to send HTTP requests.
;; https://edicl.github.io/drakma/
;; Uses Quicklisp to download and run Drakma.
;; https://www.quicklisp.org/beta/
;;
;; Requires *nix OS, be it Linux or Mac to run it.
;; (Just look at load command. Tell me if you happen to have a better idea.
;;  In any case, write things you don't like in issues, that'd be nice.)
;;
;; Tested with SBCL 1.4.5 on Ubuntu 18.04.5.
;; Launching: sbcl --script tutorial.cl

(load "~/quicklisp/setup.lisp")
(ql:quickload :drakma)

;; Returns a range of numbers
(defun range (max &key (min 0) (step 1))
   (loop for n from min below max by step
      collect n))

;; Performs an HTTP request to MIDI-Toy receiver to play or stop a note
(defun note_req (mode pitch velocity)
  (drakma:http-request (format nil "http://192.168.4.1/~A?pitch=~D&velocity=~D" mode pitch velocity)))

;; Loops notes from min to max
(loop for pitch in (range 107 :min 22 :step 1)
  do (print pitch)
     (note_req "on" pitch 60)
     (sleep 0.1)
     (note_req "off" pitch 60)
     (sleep 0.1)
)
